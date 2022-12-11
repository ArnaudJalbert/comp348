
(ns a3_jalbert_arnaud_40134632.main
  (:require [clojure.string :as str])
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

; get customer name by id
(defn cust-name-by-id [cust-list id i limit]
  (when (< i limit)
  (if (== (Integer/parseInt id) (Integer/parseInt (get cust-list i)))
  (get cust-list (+ i 1))
  (recur cust-list id (+ i 4) limit))))

(defn cust-id-by-name [cust-list name i limit]
  (when (< i limit)
  (if (= name (get cust-list (+ i 1)))
  (get cust-list i)
  (recur cust-list name (+ i 4) limit))))

; Displaying a single customer
(defn display-single-cust [cust i]
  (print "\"")
  (print (get cust (+ i 1)))
  (print "\" \"")
  (print (get cust (+ i 2)))
  (print "\" \"")
  (print (str/trim (get cust (+ i 3))))
  (print "\""))
  (flush)

; Displaying all customers from a vector
(defn display-cust [cust-list curr-cust i limit]
  (when (< i limit)
  (print curr-cust)
  (print ":[")
  (flush)
  (display-single-cust cust i)
  (print "]\n")
  (flush)
  (recur cust-list (+ 1 curr-cust) (+ i 4) limit)))

; Displaying a single product
(defn display-single-prod [prod i]
  (print "\"")
  (print (get prod (+ i 1)))
  (print "\" \"")
  (print (get prod (+ i 2)))
  (print "\"")
  (flush))

; Displaying all products from vector
(defn display-prod [prod-list prod-num i limit]
  (when (< i limit)
  (print prod-num)
  (print ":[")
  (flush)
  (display-single-prod prod-list i)
  (print "]\n")
  (flush)
  (recur prod-list (+ 1 prod-num) (+ i 3) limit)))

; Displaying a single sale
(defn display-single-sale[sale cust i]
  (print "\"")
  (print (cust-name-by-id cust (get sale (+ i 1)) 0 (count cust)))
  (print "\" \"")
  (print (get sale (+ i 2)))
  (print "\" \"")
  (print (get sale (+ i 3)))
  (print "\"")
  (flush))

; Displaying all sales from vector
(defn display-sales [sales-list cust-list curr-sales i limit]
  (when (< i limit)
  (print curr-sales)
  (print ":[")
  (flush)
  (display-single-sale sales-list cust-list i)
  (print "]\n")
  (flush)
  (recur sales-list cust-list (+ 1 curr-sales) (+ i 4) limit)))

; display total sales of one customer
(defn display-total-sales [cust-list sales-list name i limit total]
  (def cust-id (cust-id-by-name cust-list name 0 (count cust-list)))
  
  (flush))

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

  (println "")

  (print-menu)

  (case (read-line)
    "1" (display-cust cust 1 0 (count cust))
    "2" (display-prod products 1 0 (count products))
    "3" (display-sales sales cust 1 0 (count sales))
    "4" (display-total-sales cust sales "Sue Jones" 0 (count sales) 0)
    "5" (display-count-product)
    "6" (System/exit 0)
    (println "Invalid input, try again!"))

  (recur))

(menu-loop)


