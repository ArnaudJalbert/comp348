(ns test.test
  (:use [clojure.repl]))


(defn foo 
  "Foo is great.
  But it doesn't do anyting useful
  with the `bar` parameter\n"
  [bar]
  (println "in foo with " bar))


(defn start
  "This is it"
  []
  (println "Calling foo")
  (foo 26))



(start)


(doc foo)