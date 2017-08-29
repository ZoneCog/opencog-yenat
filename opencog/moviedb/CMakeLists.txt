#ADD_GUILE_MODULE (FILES
#	moviedb.scm
	
#	MODULE_DESTINATION "${DATADIR}/scm/opencog/moviedb"
#)

# Build C++ code for moviedb atom-types.
ADD_SUBDIRECTORY (types)

INSTALL (FILES
	moviedb.scm
	DESTINATION "${DATADIR}/scm/opencog/moviedb"
)
