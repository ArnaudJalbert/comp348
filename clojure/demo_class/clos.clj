(ns test.clos)

(defn outer
  [arg1]
  (fn [arg2] (* arg1 arg2)))


; create "versions" of the outer method, each with
; unique local "instance" data
(def v6 (outer 6))  ; arg1 is set to 6, basically returns (fn [arg2] (* 6 arg2))
(def v3 (outer 3))  ; arg1 is set to 3, basically returns (fn [arg2] (* 3 arg2))


; now invoke the partially instantiated functions with a second value
(println "call v6 with 4:" (v6 4))
(println "call v6 with 8:" (v6 8))

(println "call v3 with 4:" (v3 4))
(println "call v3 with 8:" (v3 8))
                  
                  