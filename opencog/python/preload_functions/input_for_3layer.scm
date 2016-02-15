(use-modules (opencog) (opencog exec))
(cog-execute!
(ExecutionOutputLink 
(GroundedSchemaNode "py: 3layer_neural_net.simneu")
(ListLink
(ArrayNode "(0,0,1),(0,1,1),(1,0,1),(1,1,1)")
(ArrayNode "(0,1,1,0)")
)))
