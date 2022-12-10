(ns test.bar)

(defn barFunc
  [x]
  (str "This is " x " in bar"))


(defn- hidden
  [y]
  (* (* y y) y))