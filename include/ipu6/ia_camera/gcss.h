/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2016-2018 Intel Corporation. All Rights Reserved.
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
#ifndef __GCSS_H__
#define __GCSS_H__

#include <ia_tools/css_types.h>
#include <ia_cipf/ia_cipf_types.h>

#ifdef __cplusplus

#include <string>
#include <map>
#include <utility>
#include <vector>

namespace GCSS {

/* For now there is no C API to GCSS so exposing the ItemUID and IGraphConfig
 * here */
class ItemUID
{
public:
    static ia_uid str2key(const std::string&);
    static const char* key2str(const ia_uid key);
    static bool isInteger(const ia_uid key);
    static ia_uid generateKey(const std::string&);
    static void addCustomKeyMap(std::map<std::string, ia_uid> &osMap);

    ItemUID(std::initializer_list<ia_uid> uids) {
        mUids.insert(mUids.end(), uids.begin(), uids.end());
    };
    ItemUID (const std::string &itemName);
    ItemUID() {};
    void pop_back() { mUids.pop_back(); };
    void push_back( const ia_uid& iuid) { mUids.push_back(iuid); };

    bool operator == (const ItemUID& v) const {
        return v.mUids == mUids;
    }

    std::string toString() const;

    std::size_t size() const { return mUids.size(); };

    ItemUID(const ItemUID &ref) { mUids = ref.mUids; };
    ItemUID & operator=(const ItemUID &v) {
        // check for self-assignment
        if (&v == this)
            return *this;

        mUids = v.mUids;
        return *this;
    }

    ia_uid& operator[](std::size_t idx) { return mUids[idx]; }
    const ia_uid& operator[](std::size_t idx) const
    { return mUids[idx]; }

private:
    friend bool operator<(const ItemUID &r, const ItemUID &l);
    friend bool operator>(const ItemUID &r, const ItemUID &l);
    std::vector<ia_uid> mUids;

};

class IGraphConfig
{
public:
    virtual ~IGraphConfig() {}

    /**
     * Get root level node of the graph
     *
     * \ingroup gcss
     *
     * \return pointer to root node on success
     * \return NULL if error
     */
    virtual IGraphConfig* getRoot(void) const = 0;
    /*
     * Get ancestor for the node
     *
     * \ingroup gcss
     *
     * \return pointer to ancestor node on success
     * \return NULL if error
     */
    virtual IGraphConfig* getAncestor(void) const = 0;

    virtual uint32_t getDescendantCount() const = 0;

    /**
     * Get descendant by GCSS_KEY
     *
     * \ingroup gcss
     *
     * \return pointer to the descendant if success
     * \return NULL if error
     */
    virtual IGraphConfig* getDescendant(ia_uid) const = 0;

    /**
     * Get descendant by GCSS_KEY, or array of keys
     *
     * \ingroup gcss
     *
     * possible usages:
     * getDescendant(GCSS_KEY_GRAPH);
     * getDescendant({GCSS_KEY_GRAPH, GCSS_KEY_CONNECTION});
     *
     * \return pointer to the descendant if success
     * \return NULL if error
     */

    virtual IGraphConfig* getDescendant(const ItemUID&) const = 0;
    /**
     * DEPRECATED
     * Get descendant by string
     *
     * \ingroup gcss
     *
     * \return pointer to the descendant if success
     * \return NULL if error
     */
    virtual IGraphConfig* getDescendantByString(const std::string &str) const = 0;

    /**
     * Get int value for an attribute given as GCSS_KEY
     *
     * \ingroup gcss
     *
     * \param[in] gcss key
     * \param[out] int value
     * \return css_err_none if success
     */
    virtual css_err_t getValue(ia_uid, int&) const = 0;
    virtual css_err_t getValue(const ItemUID&, int&) const = 0;

    /**
     * Get str value for an attribute given as GCSS_KEY
     *
     * \ingroup gcss
     *
     * \param[in] gcss key
     * \param[out] str value
     * \return css_err_none if success
     */
    virtual css_err_t getValue(ia_uid, std::string&) const = 0;
    virtual css_err_t getValue(const ItemUID&, std::string&) const = 0;

    /**
     * Set int value for an attribute given as GCSS_KEY
     *
     * \ingroup gcss
     *
     * \param[in] gcss key
     * \param[in] int value
     * \return css_err_none if success
     */

    virtual css_err_t setValue(ia_uid, int) = 0;
    virtual css_err_t setValue(const ItemUID&, int) = 0;

    /**
     * Set str value for an attribute given as GCSS_KEY
     *
     * \ingroup gcss
     *
     * \param[in] gcss key
     * \param[in] str value
     * \return css_err_none if success
     */
    virtual css_err_t setValue(ia_uid, const std::string&) = 0;
    virtual css_err_t setValue(const ItemUID&, const std::string&) = 0;

    /* Helpers to get uid of the node. Either as a string or uint*/
    virtual std::string getName()const = 0;
    virtual ia_uid getUid() const = 0;

    /**
    * Check if node in the graph is of given type
    *
    * \ingroup gcss
    *
    * Check if node is, for example, sink, port, program group.
    *
    * \param[in] type to compare against as a gcss key
    * \return true if type matches, false otherwise
    */
    virtual bool isType(ia_uid) const = 0;

};

/**
* \class NodeIterator
* \ingroup gcss
* allows iteration of descendants by type, name or value
*/
class NodeIterator
{
public:
    /**
    * Iterator is constructed by givin pointer to the IGraphConfig object
    * that is being iterated.
    * \ingroup gcss
    */
    NodeIterator(const IGraphConfig *node) : mCurrentIndex(0), mTarget(node), mCurrentKey(0) {}

    /**
    * Iterates descendants of the node by their type
    * \ingroup gcss
    * \param[in] type           Gcss key of the type to iterate
    * \return    IGraphConfig   As long as descendants found
    * \return    NULL           When end reached
    */
    IGraphConfig* iterateByType(const ia_uid &type);

    /**
    * Iterates descendants of the node with a given uid
    *
    * \ingroup gcss
    * \param[in] uid            Descendant uid as a gcss key
    * \return    IGraphConfig   As long as matching descendants found
    * \return    NULL           When end reached
    */

    IGraphConfig* iterateByUid(const ia_uid &name);

    /**
    * Iterates all descendants of the node
    *
    * \ingroup gcss
    * \return    IGraphConfig   As long as matching descendants found
    * \return    NULL           When end reached
    */
    IGraphConfig* iterateDescendants();
private:
    IGraphConfig* iterateNodes(const ia_uid &type, const std::string &str);
    IGraphConfig* reset();
    int32_t mCurrentIndex; /**< state of the iterator */
    const IGraphConfig *mTarget;   /**< node being iterated */
    // for caching key to string conversions
    ia_uid mCurrentKey;
    std::string mCurrentString;
};
} // namespace

extern "C" {
#endif

#define GCSS_KEY(key, str) GCSS_KEY_##key,
#define GCSS_KEY_SECTION_START(key, str, val) GCSS_KEY_##key = val,
#define GCSS_KEY_SECTION_END(key, str, val) GCSS_KEY_##key = val,
typedef enum _GraphConfigKey {
    #include "gcss_keys.h"
    GCSS_KEY_START_CUSTOM_KEYS = 0x8000,
} GraphConfigKey;
#undef GCSS_KEY
#undef GCSS_KEY_SECTION_START
#undef GCSS_KEY_SECTION_END

#ifdef __cplusplus
}
#endif

#endif
