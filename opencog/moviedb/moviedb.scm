
(use-modules (opencog) (opencog atom-types))
(define-module (opencog moviedb))


; Load various parts....


(load-extension "libmoviedb-types" "moviedb_types_init")

;(add-to-load-path "/usr/local/share/opencog/scm")
;(use-modules (opencog))  ; needed for cog-type->int

(load "moviedb/types/moviedb_types.scm")
