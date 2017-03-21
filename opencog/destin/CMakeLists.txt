# Always build the atom types, even if not building the rest of
# destin.
OPENCOG_ADD_ATOM_TYPES(atom_types.script
	atom_types.h
	atom_types.definitions
	atom_types.inheritance
	destin_types.scm
	destin_types.pyx)
ADD_CUSTOM_TARGET(destin_atom_types DEPENDS atom_types.h)

# The atom_types.h file is written to the build directory
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR})

ADD_LIBRARY (destin-types SHARED
	atom_types_init.cc
	DestinAtomTypesTester
	DestinAtomTypesModule
	
)

ADD_DEPENDENCIES(destin-types destin_atom_types)
ADD_DEPENDENCIES(destin-types attention_atom_types)

TARGET_LINK_LIBRARIES (destin-types
	${ATOMSPACE_atombase_LIBRARY}
)

INSTALL (FILES
  	${CMAKE_CURRENT_BINARY_DIR}/destin_types.scm
  	DESTINATION "${DATADIR}/scm/destin"
)

INSTALL (TARGETS destin-types
	LIBRARY DESTINATION "lib${LIB_DIR_SUFFIX}/opencog/modules")
