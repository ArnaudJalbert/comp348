(ns test.simple)


; reverse the values within a vector
(defn flip 
  [numbers]
  (if (empty? numbers)
    []
    (conj (flip (rest numbers)) (first numbers) )))

(println (flip [1 2 3 4 5 6 7 8 9] ))



