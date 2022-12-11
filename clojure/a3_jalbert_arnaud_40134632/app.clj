
(ns app
  (:require [clojure.string :as str])
  (:require [menu])
  (:require [db])
  (:gen-class))

; Function to parse the text into a vector
(defn parse-txt [path]
  (def file-txt (str/replace (slurp path) #"\n" "|"))
  (str/split (str file-txt) #"\|"))

; Parsing customer file
(def cust (parse-txt "cust.txt"))

; Parsing products file
(def products (parse-txt "products.txt"))

; Parsing sales file
(def sales (parse-txt "sales.txt"))

(menu/menu-loop cust products sales)


