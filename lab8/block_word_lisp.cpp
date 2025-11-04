(defparameter *initial-state*
  '((on a table)
    (on b table)
    (on c a)
    (clear b)
    (clear c)))

(defparameter *goal-state*
  '((on a b)
    (on b c)
    (on c table)))

(defun member-state (x state)
  (member x state :test #'equal))

(defun add-state (fact state)
  (adjoin fact state :test #'equal))

(defun del-state (fact state)
  (remove fact state :test #'equal))

(defun goal-reached? (state)
  (every (lambda (g) (member-state g state)) *goal-state*))

(defun valid-move? (state block from to)
  "Return T if moving BLOCK from FROM to TO is valid."
  (and (not (equal from to))
       (member-state `(on ,block ,from) state)
       (member-state `(clear ,block) state)
       (or (equal to 'table)
           (member-state `(clear ,to) state))))

(defun apply-move (state block from to)
  "Return new state after moving BLOCK from FROM to TO."
  (let ((new-state (copy-list state)))
    (setf new-state (del-state `(on ,block ,from) new-state))
    (setf new-state (add-state `(on ,block ,to) new-state))
    (when (not (equal from 'table))
      (setf new-state (add-state `(clear ,from) new-state)))
    (when (not (equal to 'table))
      (setf new-state (del-state `(clear ,to) new-state)))
    new-state))

(defun plan (state visited)
  "Return a sequence of actions that lead from STATE to the goal."
  (cond
    ((goal-reached? state)
     (list 'goal-reached))

    (t
     (loop for b in '(a b c)
           append
           (loop for x in '(a b c table)
                 append
                 (loop for y in '(a b c table)
                       unless (or (equal x y)
                                  (equal b x)
                                  (equal b y))
                       append
                       (when (valid-move? state b x y)
                         (let ((new-state (apply-move state b x y)))
                           (unless (member new-state visited :test #'equal)
                             (let ((rest (plan new-state (cons new-state visited))))
                               (when rest
                                 (return-from plan
                                   (cons (list 'move b x y) rest))))))))))
     nil)))

(defun solve ()
  (let ((solution (plan *initial-state* (list *initial-state*))))
    (if solution
        (progn
          (format t "~%Solution found:~%")
          (dolist (step solution)
            (format t "  ~A~%" step)))
        (format t "No solution found.~%"))))

