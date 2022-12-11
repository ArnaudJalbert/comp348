(ns menu
  (:require [clojure.string :as str])
  (:require [db])
  (:gen-class))

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

(defn quit[]
  (println "Goodbye!")
  (System/exit 0)
)
(defn menu-loop [cust products sales]

  (println "")

  (print-menu)
  (flush)

  (case (read-line)
    "1" (db/display-cust cust 1 0 (count cust))
    "2" (db/display-prod products 1 0 (count products))
    "3" (db/display-sales products sales cust 1 0 (count sales))
    "4" (db/launch-total-sales cust sales products)
    "5" (db/launch-count-product products sales)
    "6" (quit)
    (println "Invalid input, try again!"))

  (recur cust products sales))