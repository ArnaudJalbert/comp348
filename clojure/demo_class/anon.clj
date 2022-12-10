(ns test.anon)

; a function passed to another function
(defn silly
  [new_func item]
  (new_func item))

(defn putty
  [item]
  (println "Item is just:" item))


(silly putty 6)










; an anoymous function instead
(defn twice
  [data]
  (map (fn [arg] (* arg 2)) data))

(def result (twice [2 3 4 5 6]))
(println "result:" result)








(println
  "reduce list: " (reduce + [14 2 16 42]))

(def filtered (filter (fn [x] (< x 2)) [-1 4 0 7]))
(println "filter list:" filtered)
























