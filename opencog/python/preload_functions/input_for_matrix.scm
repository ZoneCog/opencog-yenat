(use-modules (opencog) (opencog exec))
(cog-execute!
(ExecutionOutputLink 
(GroundedSchemaNode "py: matrix_multiplication.string_to_array")
(ListLink
(ArrayNode "(1,2),(3,4),(5,6)")
(ArrayNode "(1,2,3),(4,5,6)")
)))
