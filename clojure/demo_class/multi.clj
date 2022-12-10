(ns test.multi)


; basic multi-arity function
(defn foo 
  ([]
    (println "no args version"))
  
  ([p1]
    (println "p1:" p1))
  
  ([p1 p2]
    (println "p1:" p1 " p2:" p2))
  
  ([p1 p2 p3]
    (println "p1:" p1 " p2:" p2 " p3:" p3)))

(foo)
(foo "one")
(foo "one" "two")
(foo "one" "two" "three")








; multi-arity that calls itself
(defn boo
  ([one]
    (str "I say " one))
  
  ([one two]
    (str (boo one) " and then I say " two)))

(println (boo "stuff"))
(println (boo "goo" "thing"))




















  
  
