
(ns a3_jalbert_arnaud_40134632.main
  (:require [clojure.string :as str])
  (:gen-class))

(defn parse-txt [path]
  (def file-txt (slurp path))
  (str/split (str file-txt) #"\|"))

(def cust (parse-txt "cust.txt"))

(def products (parse-txt "products.txt"))

(def sales (parse-txt "sales.txt"))

(defn display-cust []
  (parse-txt "cust.txt")
  (println "Displaying customer "))

(defn display-prod []
  (println "Displaying customer "))

(defn display-sales []
  (println "Displaying customer "))

(defn display-total-sales []
  (println "Displaying customer "))

(defn display-count-product []
  (println "Displaying customer "))

(defn print-menu []
  (print "*** Sales Menu ***\n")
  (print "------------------\n")
  (print "1. Display Customer Table\n")
  (print "2. Display Product Table\n")
  (print "3. Display Sales Table\n")
  (print "4. Total Sales for Customer\n")
  (print "5. Total Count for Product\n")
  (print "6. Exit\n\n")
  (print "Enter an option?\n")
  (flush))

(defn menu-loop []

  (print-menu)

  (case (read-line)
    "1" (display-cust)
    "2" (display-prod)
    "3" (display-sales)
    "4" (display-total-sales)
    "5" (display-count-product)
    "6" (System/exit 0)
    (println "Invalid input, try again!"))

  (recur))
(println cust)
(println products)
(println sales)
(flush)

(menu-loop)









