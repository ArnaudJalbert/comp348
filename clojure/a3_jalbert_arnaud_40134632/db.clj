(ns db
  (:require [clojure.string :as str])
  (:gen-class))

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

; gets the price of one product
(defn get-prod-price [prod-list id i limit]
  (when (< i limit)
    (if (== ( Integer/parseInt id) (Integer/parseInt (get prod-list i)))
      ; IF
      (get prod-list (+ i 2))
      ;ELSE
      (recur prod-list id (+ i 3) limit))
  )
)

(defn get-prod-id [prod-list name i limit]
  (when (< i limit)
    (if (= name (get prod-list (+ i 1)))
      ; IF
      (get prod-list i)
      ;ELSE
      (recur prod-list name (+ i 3) limit))
  )
)

(defn get-prod-name-by-id [prod-list id i limit]
  (when (< i limit)
    (if (= id (get prod-list i))
      ; IF
      (get prod-list (+ i 1))
      ;ELSE
      (recur prod-list id (+ i 3) limit))
  )
)
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
  (display-single-cust cust-list i)
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
(defn display-single-sale[products sale cust i]
  (print "\"")
  (print (cust-name-by-id cust (get sale (+ i 1)) 0 (count cust)))
  (print "\" \"")
  (print (get-prod-name-by-id products (get sale (+ i 2)) 0 (count products)))
  (print "\" \"")
  (print (get sale (+ i 3)))
  (print "\"")
  (flush))

; Displaying all sales from vector
(defn display-sales [products sales-list cust-list curr-sales i limit]
  (when (< i limit)
  (print curr-sales)
  (print ":[")
  (flush)
  (display-single-sale products sales-list cust-list i)
  (print "]\n")
  (flush)
  (recur products sales-list cust-list (+ 1 curr-sales) (+ i 4) limit)))

; returns the price of one sale entry
(defn sale-from [sale prod-list cust-id i]

  (def quant (Double/valueOf (get sale (+ i 3))))

  (def price (Double/valueOf (get-prod-price prod-list (get sale (+ i 2)) 0 (count prod-list))))

  (def value-def 0.0)
  
  (if (== (Integer/parseInt cust-id) (Integer/parseInt (get sale (+ i 1))))
    (* quant price)
    value-def
  )
)

; display total sales of one customer
(defn display-total-sales [cust-list sales-list prod-list name i limit total]

  (def cust-id (cust-id-by-name cust-list name 0 (count cust-list)))

  (if (nil? cust-id) (println name ":" total))

  (if (== i limit) (println name ": " total) ())

  (when (and (< i limit) cust-id)

    (if (complement (nil? cust-id))
      (def new-total (sale-from sales-list prod-list cust-id i))
      ; ELSE
      (def new-total 0.0))
    ;RECUR
    (recur cust-list sales-list prod-list name (+ i 4) limit (+ total new-total))
  )
)

(defn launch-total-sales[cust sales products]
  (print "Customer: ")
  (flush)
  (def customer (str (read-line)))
  (display-total-sales cust sales products customer 0 (count sales) 0.0)
)

(defn display-count-product [products sales name i limit total]

  (def prod-id (get-prod-id products name 0 (count products)))

  (if (== i limit) (print name ":" total))

  (when (< i limit)
    (if (= prod-id (get sales (+ i 2)))

      (def new-total (+ total (Integer/parseInt (get sales (+ i 3)))))
    
      (def new-total total)
    )

    (recur products sales name (+ i 4) limit new-total)
  )
)

(defn launch-count-product[products sales]

  (print "Product: ")
  (flush)
  (def product (str (read-line)))
  (display-count-product products sales product 0 (count sales) 0)
)