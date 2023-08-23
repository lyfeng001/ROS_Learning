;; Auto-generated. Do not edit!


(when (boundp 'snake_test::Serpentine)
  (if (not (find-package "SNAKE_TEST"))
    (make-package "SNAKE_TEST"))
  (shadow 'Serpentine (find-package "SNAKE_TEST")))
(unless (find-package "SNAKE_TEST::SERPENTINE")
  (make-package "SNAKE_TEST::SERPENTINE"))

(in-package "ROS")
;;//! \htmlinclude Serpentine.msg.html


(defclass snake_test::Serpentine
  :super ros::object
  :slots (_alphaH _alphaW _gamma ))

(defmethod snake_test::Serpentine
  (:init
   (&key
    ((:alphaH __alphaH) 0.0)
    ((:alphaW __alphaW) 0.0)
    ((:gamma __gamma) 0.0)
    )
   (send-super :init)
   (setq _alphaH (float __alphaH))
   (setq _alphaW (float __alphaW))
   (setq _gamma (float __gamma))
   self)
  (:alphaH
   (&optional __alphaH)
   (if __alphaH (setq _alphaH __alphaH)) _alphaH)
  (:alphaW
   (&optional __alphaW)
   (if __alphaW (setq _alphaW __alphaW)) _alphaW)
  (:gamma
   (&optional __gamma)
   (if __gamma (setq _gamma __gamma)) _gamma)
  (:serialization-length
   ()
   (+
    ;; float64 _alphaH
    8
    ;; float64 _alphaW
    8
    ;; float64 _gamma
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _alphaH
       (sys::poke _alphaH (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _alphaW
       (sys::poke _alphaW (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _gamma
       (sys::poke _gamma (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _alphaH
     (setq _alphaH (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _alphaW
     (setq _alphaW (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _gamma
     (setq _gamma (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get snake_test::Serpentine :md5sum-) "02f2567fa94bc953e03c031ebb7a9a8e")
(setf (get snake_test::Serpentine :datatype-) "snake_test/Serpentine")
(setf (get snake_test::Serpentine :definition-)
      "float64 alphaH
float64 alphaW
float64 gamma 

")



(provide :snake_test/Serpentine "02f2567fa94bc953e03c031ebb7a9a8e")


