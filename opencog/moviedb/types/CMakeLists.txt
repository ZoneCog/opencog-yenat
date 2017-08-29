# Always build the atom types, even if not building the rest of
# moviedb.
OPENCOG_ADD_ATOM_TYPES(atom_types.script
	atom_types.h
	atom_types.definitions
	atom_types.inheritance
	moviedb_types.scm
	moviedb_types.pyx)
ADD_CUSTOM_TARGET(moviedb_atom_types DEPENDS atom_types.h)

# The atom_types.h file is written to the build directory
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR})

ADD_LIBRARY (moviedb-types SHARED
	atom_types
	atom_types_init

	
)
# Build C++ code in assorted moviedb subdirectories

TARGET_LINK_LIBRARIES (moviedb-types
	${ATOMSPACE_LIBRARIES}
)
#ADD_SUBDIRECTORY (scm)
#ADD_SUBDIRECTORY (types)


ADD_DEPENDENCIES(moviedb-types moviedb_atom_types)

INSTALL (TARGETS moviedb-types
	LIBRARY DESTINATION "lib${LIB_DIR_SUFFIX}/opencog"
)

INSTALL (FILES
	${CMAKE_CURRENT_BINARY_DIR}/atom_types.h
	DESTINATION "include/${PROJECT_NAME}/moviedb/types"
)

INSTALL (FILES
	${CMAKE_CURRENT_BINARY_DIR}/moviedb_types.scm
	DESTINATION "${DATADIR}/scm/opencog/moviedb/types"
)
