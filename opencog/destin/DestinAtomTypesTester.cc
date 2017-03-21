/*

 *
 * Copyright (C) 2008 by Singularity Institute for Artificial Intelligence
 * All Rights Reserved
 *
 * Written by Gustavo Gama <gama@vettalabs.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License v3 as
 * published by the Free Software Foundation and including the exceptions
 * at http://opencog.org/wiki/Licenses
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to:
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "DestinAtomTypesTester.h"

#include <opencog/atomspace/AtomSpace.h>
#include <opencog/atoms/base/Link.h>
#include <opencog/atoms/base/Node.h>
#include <opencog/atoms/base/types.h>
#include <opencog/cogserver/server/CogServer.h>
#include <opencog/util/Logger.h>

#include "atom_types.h"

using namespace opencog;

void DestinAtomTypesTester::createAtoms()
{
    logger().info("[DestinAtomTypesTester.createAtoms]");

    AtomSpace& as = server().getAtomSpace();

    Handle number_handle = as.add_node(NUMBER_NODE,"1");
    logger().info("[DestinAtomTypesTester] new node: %s (%d)",
            number_handle->toString().c_str(), number_handle.value());

    Handle region_handle = as.add_node(REGION_NODE, "region");

    logger().info("[DestinAtomTypesTester] new node: %s (%d)",

            region_handle->toString().c_str(), region_handle.value());

    Handle array_handle = as.add_node(ARRAY_NODE, "array");
    logger().info("[DestinAtomTypesTester] new node: %s (%d)",
            array_handle->toString().c_str(), array_handle.value());

    Handle spatiotemporalnetwork_handle = as.add_node(SPATIOTEMPORALNETWORK_NODE, "spatiotemporalnetwork");
    logger().info("[DestinAtomTypesTester] new node: %s (%d)",
            spatiotemporalnetwork_handle->toString().c_str(), spatiotemporalnetwork_handle.value());

           
   
    std::vector<Handle> v;
    v.push_back(array_handle);
    v.push_back(spatiotemporalnetwork_handle);
    v.push_back(region_handle);

    
    Handle regionchild_handle = as.add_link(REGIONCHILD_LINK, v);
    logger().info("[DestinAtomTypesTester] new link: %s (%d)",


            regionchild_handle->toString().c_str(), regionchild_handle.value());

    Handle regionneighbor_handle = as.add_link(REGIONNEIGHBOR_LINK, v);

    logger().info("[DestinAtomTypesTester] new link: %s (%d)",

    
            regionneighbor_handle->toString().c_str(), regionneighbor_handle.value());

    Handle list_handle = as.add_link(LIST_LINK, v);
    logger().info("[DestinAtomTypesTester] new link: %s (%d)",
            list_handle->toString().c_str(), list_handle.value());
}

static void dumpHandleSeq(HandleSeq& hs, const char *id)
{
    for( Handle handle: hs) {

        logger().info("[DestinAtomTypesTester] %s: %s",

        
                id, handle->toString().c_str());
    }
}

void DestinAtomTypesTester::dumpAtoms()
{
    logger().info("[DestinAtomTypesTester.dumpAtoms]");
    AtomSpace& as = server().getAtomSpace();
    HandleSeq hs;
    
    as.get_handles_by_type(back_inserter(hs), NODE, true);
    dumpHandleSeq(hs, "node");
    hs.clear();
    
    as.get_handles_by_type(back_inserter(hs), REGIONCHILD_LINK);
    dumpHandleSeq(hs, "regionchild link");
    hs.clear();
    as.get_handles_by_type(back_inserter(hs), REGIONNEIGHBOR_LINK);
    dumpHandleSeq(hs, "regionneighbor link");
    hs.clear();
    as.get_handles_by_type(back_inserter(hs), REGIONCHILD_LINK);
    dumpHandleSeq(hs, "regionchild link");
    hs.clear();
    as.get_handles_by_type(back_inserter(hs), REGIONNEIGHBOR_LINK);
    dumpHandleSeq(hs, "regionneighbor link");
    hs.clear();
    as.get_handles_by_type(back_inserter(hs), UNORDERED_LINK, true);
    dumpHandleSeq(hs, "unordered link");
    hs.clear();
    as.get_handles_by_type(back_inserter(hs), LINK, true);
    dumpHandleSeq(hs, "link");
    hs.clear();
}
