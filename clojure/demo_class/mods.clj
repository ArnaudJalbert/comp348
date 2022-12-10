(ns test.mods
  (:require [clojure.string :as str])
  (:require [clojure.set :as set :refer[union]]) ; union not qualified
  (:import java.lang.String)
  (:import java.util.Date))  ; fully qualified Java name not required
  

(println "string test...")

(def sample "my dog is a pest")

; fully qualified function name
(println "capitalizing first char of:" sample)
(println (clojure.string/capitalize sample))


; use the short form of the module
(println "\ncapitalizing all chars of:" sample)
(println (str/upper-case sample))


; using a regular expression
(println "\nsplitting the string:" sample)
(println (str/split sample #"\s+"))


; working with a specific set function
(def s1 #{1 2 3 4 5})
(def s2 #{6 7 5 4 3})

(println "\nset difference on:" s1 s2)
(println (set/difference s1 s2))  ; difference needs to be fully qualified

(println "\nset union on:" s1 s2)
(println (union s1 s2))    ; union does not need to be fully qualified


; some Java stuff

; now do it with a java string
(def jstr (String. "my dog is a pest"))
(println "\njava string:" jstr) 
(println "java string upper case: " (.toUpperCase jstr)) 


(println "\ndisplay the time")
(println "timestamp 1: " (. (Date.) getTime))

(def timestamp (Date.))
(println "timestamp 2: " (. timestamp getTime)) ; "." to invoke a method on a new (Date.) object
(println "timestamp 3: " (.getTime timestamp)) ; alternative syntax same thing.

(println "human readable time: " (.toString timestamp)) ; extract the year


