
(ns a3_jalbert_arnaud_40134632.test
  (:require [clojure.string :as str])
  (:gen-class))

(def new-string "Hello World")

(format "This is string %s" new-string)
(format "leading zeros ")

(list "dog" 1 2 3 4)

(print (str/includes? "Allo" "Al"))
(print (str/split "yo ca va?" #" ") [0])
(print (list 1 2 3 4))

