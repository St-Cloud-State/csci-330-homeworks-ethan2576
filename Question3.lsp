(defun make-pairs (lst)
  "Converts a list into a list of sorted pairs."
  (if (null lst)
      nil
      (if (null (cdr lst))
          (list lst)  ;; Single remaining element is a valid sublist
          (cons (sort (list (car lst) (cadr lst)) #'<)   ;; Sort each pair
                (make-pairs (cddr lst))))))  ;; Process the rest of the list

(defun merge-sorted (lst1 lst2)
  "Merges two sorted lists into one sorted list."
  (cond
    ((null lst1) lst2)
    ((null lst2) lst1)
    ((<= (car lst1) (car lst2))
     (cons (car lst1) (merge-sorted (cdr lst1) lst2)))
    (t
     (cons (car lst2) (merge-sorted lst1 (cdr lst2))))))

(defun bottom-up-mergesort (lst)
  "Sorts a list using the bottom-up iterative Merge Sort algorithm."
  (let ((pairs (make-pairs lst)))  ;; Step 1: Convert list into sorted pairs
    (loop while (> (length pairs) 1) do
          (setq pairs (merge-pass pairs)))  ;; Step 2: Merge adjacent lists iteratively
    (car pairs)))  ;; Return the final sorted list

