(use-modules (opencog) (opencog exec) (opencog python))

(python-eval "three_layer_neural_net.simneu")

(cog-execute!
(ExecutionOutputLink 
(GroundedSchemaNode "py:three_layer_neural_net.simneu")
(ListLink
(ArrayNode "(0,0,1),(0,1,1),(1,0,1),(1,1,1)")
(ArrayNode "(0,1,1,0)"))))


(use-modules (opencog) (opencog exec) (opencog python))

(python-eval "matrix_multiplication.string_to_array")

(cog-execute!
(ExecutionOutputLink 
(GroundedSchemaNode "py:matrix_multiplication.string_to_array")
(ListLink
(ArrayNode "(1,2),(3,4),(5,6)")
(ArrayNode "(1,2,3),(4,5,6)"))))


(use-modules (opencog) (opencog exec) (opencog python))

(python-eval "convae_destin_1")

(cog-execute!
(ExecutionOutputLink 
(GroundedSchemaNode "py:convae_destin_1")
(ListLink)))
