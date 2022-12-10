(ns test.recurz)



; iterative summation function
;
; int sum(int *items, int size){
;   int sum = 0;
;   int i;
;   for(i = 0; i < size; i++){
;     sum += items[i];
;   }
;   return sum;


; Compute the sum of a sequence
(defn sum
  ([items] (sum items 0))       ; call sum with 2 args: item list and 0
  
  ([items total]               ; 2 parm version: items list and running total 
     (if (empty? items)        
       total                 ; if vals is now empty, return total
       (sum (rest items) (+ (first items) total))))) 
       ; else recursive call: sum(rest of items, (first item + running total))


; same function using recur
(defn sum2
  ([items] (sum items 0))       
  
  ([items total]              
     (if (empty? items)        
       total                 
       (recur (rest items) (+ (first items) total))))) 


(println (sum [10 20 30 40]))
(println (sum2 [10 20 30 40]))














