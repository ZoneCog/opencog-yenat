(use-modules (opencog) (opencog exec))
(cog-execute!
(ExecutionOutputLink 
(GroundedSchemaNode "py: matrix_multiplication.string_to_array")
(ListLink
(ArrayNode "(1,2,3,4,5),(3,4,4,5,6),(5,6,1,2,3),(1,2,3,1,6),(3,4,6,7,8),(5,6,4,5,6)")
(ArrayNode "(1,2,3,4,5,6,7,8,9,10),(4,5,6,1,2,3,4,5,6,7),(1,2,3,4,5,6,7,8,9,10),(1,2,3,4,5,6,7,8,9,10),(4,5,6,1,2,3,4,5,6,7)")
)))


(use-modules (opencog) (opencog exec))
(cog-execute!
(ExecutionOutputLink 
(GroundedSchemaNode "py: convae_destin_1.conv")
(ListLink

)))



(use-modules (opencog) (opencog exec))
(cog-execute!
(ExecutionOutputLink 
(GroundedSchemaNode "py: 2layer_neural_net.simneu")
(ListLink
(ArrayNode "(0,0,1),(0,1,1),(1,0,1),(1,1,1)")
(ArrayNode "(0,0,1,1)")
)))






(define test
(ExecutionOutputLink 
(GroundedSchemaNode "py: addlink.array_from_string")
(ListLink
(ArrayNode "(1,2),(3,4),(5,6)")
(ArrayNode "(1,2,3),(4,5,6)")
)))

(use-modules (opencog) (opencog exec))
(cog-execute! test)




(define test
(ExecutionOutputLink 
(GroundedSchemaNode "py: addlink.multi")
))







