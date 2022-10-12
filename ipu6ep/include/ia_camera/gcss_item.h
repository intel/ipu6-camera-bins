/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2015-2018 Intel Corporation. All Rights Reserved.
 *
 * The source code contained or described herein and all documents related to
 * the source code ("Material") are owned by Intel Corporation or its suppliers
 * or licensors. Title to the Material remains with Intel Corporation or its
 * suppliers and licensors. The Material contains trade secrets and proprietary
 * and confidential information of Intel or its suppliers and licensors. The
 * Material is protected by worldwide copyright and trade secret laws and
 * treaty provisions. No part of the Material may be used, copied, reproduced,
 * modified, published, uploaded, posted, transmitted, distributed, or
 * disclosed in any way without Intel's prior express written permission.
 *
 * No license under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or delivery
 * of the Materials, either expressly, by implication, inducement, estoppel or
 * otherwise. Any license under such intellectual property rights must be
 * express and approved by Intel in writing.
 */
#ifndef GCSS_ITEM_H_
#define GCSS_ITEM_H_

#include "gcss.h"
namespace GCSS {

class GraphQueryManager;

/** RelayControl :
* Controls of assigning GraphConfig container elements */
namespace RelayControl {
    typedef int8_t Rule;
    const Rule RELAY_RULE_ADD_NODES = 0x1;
    const Rule RELAY_RULE_HANDLE_OPTIONS = 1 << 1;
    const Rule RELAY_RULE_PROPAGATE = 1 << 2;
    const Rule RELAY_RULE_OVERWRITE = 1 << 3;
}

void getGcssKeys(std::map<std::string, ia_uid> &src);
void copyGcssKeys(std::map<std::string, ia_uid> &src);

/**
 * Holds type of the item. It can be Node or Attribute (int or string)
 */
enum Type {
    NA               = (1 << 0),
    STR_ATTRIBUTE    = (1 << 1),
    INT_ATTRIBUTE    = (1 << 2),
    NODE             = (1 << 3)
};
/**
 * \class GraphConfigItem
 * Base class that holds attributes or nodes inside
 */
class GraphConfigItem
{
public:
    typedef std::multimap<ia_uid, GraphConfigItem*> gcss_item_map;
    typedef gcss_item_map::const_iterator const_iterator;

    /** Getter for int value of attribute. Return error if getValue is being
     * used directly or if child class doesn't implement getValue
     * \param[out] value
     */

    virtual css_err_t getValue(int&) {return css_err_noentry;}
    /** Getter for string value of attribute. Return error if getValue is being
     * used directly or if child class doesn't implement getValue
     * \param[out] value
     */

    virtual css_err_t getValue(std::string&) {return css_err_noentry;}
    /** Setter for string value of attribute.
     * \param[in] new value
     */

    virtual css_err_t setValue(const std::string&) {return css_err_noentry;}
    /** Setter for int value of attribute.
     * \param[in] new value
     */
    virtual css_err_t setValue(int) {return css_err_noentry;}

    Type mType;
    GraphConfigItem(Type type) : mType(type) {}

    virtual ~GraphConfigItem() {}
};


inline bool operator<(const ItemUID &r, const ItemUID &l)
{
    return r.mUids < l.mUids;
}

inline bool operator>(const ItemUID &r, const ItemUID &l)
{
    return r.mUids > l.mUids;
}

/**
 * \class GraphConfigAttribute
 * Base class for graph config attributes
 */
class GraphConfigAttribute : public GraphConfigItem {
public:
    GraphConfigAttribute() : GraphConfigItem(NA){}
    GraphConfigAttribute(Type t) : GraphConfigItem(t){}
    ~GraphConfigAttribute() {}
};

/**
 * \class GraphConfigIntAttribute
 * Container for integer type attributes
 */
class GraphConfigIntAttribute : public GraphConfigAttribute
{
public:
    GraphConfigIntAttribute() : GraphConfigAttribute(INT_ATTRIBUTE), mInteger(-1){}
    GraphConfigIntAttribute* copy();
    css_err_t getValue(int& intVal){intVal = mInteger; return css_err_none;}
    css_err_t setValue(int intVal) { return insertInteger(intVal);}
    ~GraphConfigIntAttribute() {};
private:
    css_err_t insertInteger(int);
    int mInteger;
};

/**
 * \class GraphConfigStrAttribute
 * Container for string type attributes
 */
class GraphConfigStrAttribute : public GraphConfigAttribute
{
public:
    GraphConfigStrAttribute() : GraphConfigAttribute(STR_ATTRIBUTE){}
    GraphConfigStrAttribute* copy();
    css_err_t getValue(std::string& str){str = mString; return css_err_none;}
    css_err_t setValue(const std::string& str) { return insertString(str);}
    ~GraphConfigStrAttribute() {};
private:
    css_err_t insertString(const std::string&);
    std::string mString;
};

/**
 * \class GraphConfigNode
 * Provides methods for manipulating nodes in the graph
 */
class GraphConfigNode : public GraphConfigItem, public IGraphConfig
{
public:
    GraphConfigNode(const GraphConfigNode&);
    GraphConfigNode() : GraphConfigItem(NODE), mAncestor(NULL){};
    ~GraphConfigNode();

    GraphConfigNode* copy() const;
    operator IGraphConfig*() { return this; }
    static void dumpNodeTree(const GraphConfigNode*, int depth  = 0);
    const_iterator begin() const { return mItem.begin(); }
    const_iterator end() const { return mItem.end(); }

    css_err_t insertDescendant(GraphConfigItem*, const ia_uid);
    css_err_t removeDescendant(const ia_uid);
    css_err_t createAttribute(const ItemUID& item, GraphConfigAttribute** ret);

    css_err_t changeBaseNodeIntoNode(GraphConfigNode &configNode);

    /**
     * Helper function which iterates through given node and search for
     * matching attribute. Return error if not found.
     * \param attribute the ItemUID of attribute to search
     * \param searchAttributeValue the value to search
     * \param it iterator for the node to search
     * \return css_err_t
     */
    template <typename T>
    css_err_t iterateAttributes(ia_uid attribute,
        const T& searchAttributeValue,
        const const_iterator& it) const;

    static css_err_t handleAttributeOptions(GraphConfigNode *node,
        ia_uid attribute_key,
        const std::string &newValue);

    /** DEPRECATED public methods, use IGraphConfig implementations instead */
    GraphConfigNode* getRootNode(void) const;
    css_err_t getAncestor(GraphConfigNode**);
    css_err_t getAttribute(const ia_uid iuid, GraphConfigAttribute** ret) const;
    css_err_t getAttribute(const ItemUID& item, GraphConfigAttribute** ret) const;
    css_err_t getDescendant(const ia_uid, GraphConfigNode**) const;
    css_err_t getDescendant(const ia_uid attribute,
        const int searchAttributeValue,
        const_iterator& it,
        GraphConfigNode** retNode) const;
    css_err_t getDescendant(const ia_uid attribute,
        const std::string& searchAttributeValue,
        const_iterator& it,
        GraphConfigNode** retNode) const;
    css_err_t getDescendantByString(const std::string &str,
        GraphConfigNode **retNode);
private:
    /* private methods */
    GraphConfigNode & operator=(const GraphConfigNode &);

    GraphConfigItem::const_iterator getNext(const_iterator& it){
                                            return std::next(it, 1);}
    GraphConfigItem::const_iterator getNextAttribute(
            GraphConfigItem::const_iterator& it) const;

    template <typename T>
    css_err_t getAttrValue(const ia_uid& uid, T& val) const;

    template <typename T>
    css_err_t setAttrValue(const ia_uid& uid, T& val);

    void dumpNode();

    /* private members */
    gcss_item_map mItem; /**< map that holds GraphConfigItem objects inside */
    GraphConfigNode* mAncestor;


    css_err_t setValueFromStr(const ItemUID &iuid, const std::string val);
    virtual IGraphConfig* getGraphConfigItem(const ItemUID&) const;

public: /* implements IGraphConfig */
    virtual IGraphConfig* getRoot(void) const;
    virtual IGraphConfig* getAncestor(void) const;
    virtual IGraphConfig* getDescendant(ia_uid uid) const;
    virtual IGraphConfig* getDescendant(const ItemUID&) const;
    virtual IGraphConfig* getDescendantByString(const std::string &str) const;
    virtual uint32_t getDescendantCount() const;
    virtual css_err_t getValue(ia_uid, int&) const;
    virtual css_err_t getValue(const ItemUID&, int&) const;

    virtual css_err_t getValue(ia_uid, std::string&) const;
    virtual css_err_t getValue(const ItemUID&, std::string&) const;

    virtual css_err_t setValue(ia_uid, int);
    virtual css_err_t setValue(const ItemUID&, int);

    virtual css_err_t setValue(ia_uid, const std::string&);
    virtual css_err_t setValue(const ItemUID&, const std::string&);
    virtual std::string getName() const;
    virtual ia_uid getUid() const;
    virtual bool isType(ia_uid) const;

    /* access not part of IGraphConfig */
    bool hasItem(const ia_uid iuid) const;
    css_err_t addValue(ia_uid uid, const std::string &val);
    css_err_t addValue(ia_uid uid, int val);

    // To silence possible compiler warning
    using GraphConfigItem::getValue;
    using GraphConfigItem::setValue;
};
/* class to expose GraphConfigNode internals to GraphQueryManager */
class GraphQueryUtils : public GraphConfigNode {
public:
    static css_err_t addDescendantsFromNode(
        GraphConfigNode *to,
        GraphConfigNode *from,
        RelayControl::Rule rr = RelayControl::RELAY_RULE_ADD_NODES
        | RelayControl::RELAY_RULE_OVERWRITE);
private:
    static GraphConfigNode* getPortPeer(GraphConfigNode* portNode);
    static void disableUnusedPorts(GraphConfigNode *gcNode);
    static css_err_t disableNode(GraphConfigNode *);
    friend GraphQueryManager;
};
} // namespace GCSS
#endif /* GCSS_ITEM_H_ */
