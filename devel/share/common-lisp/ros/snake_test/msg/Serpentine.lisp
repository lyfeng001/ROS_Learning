; Auto-generated. Do not edit!


(cl:in-package snake_test-msg)


;//! \htmlinclude Serpentine.msg.html

(cl:defclass <Serpentine> (roslisp-msg-protocol:ros-message)
  ((alphaH
    :reader alphaH
    :initarg :alphaH
    :type cl:float
    :initform 0.0)
   (alphaW
    :reader alphaW
    :initarg :alphaW
    :type cl:float
    :initform 0.0)
   (gamma
    :reader gamma
    :initarg :gamma
    :type cl:float
    :initform 0.0))
)

(cl:defclass Serpentine (<Serpentine>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Serpentine>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Serpentine)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name snake_test-msg:<Serpentine> is deprecated: use snake_test-msg:Serpentine instead.")))

(cl:ensure-generic-function 'alphaH-val :lambda-list '(m))
(cl:defmethod alphaH-val ((m <Serpentine>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snake_test-msg:alphaH-val is deprecated.  Use snake_test-msg:alphaH instead.")
  (alphaH m))

(cl:ensure-generic-function 'alphaW-val :lambda-list '(m))
(cl:defmethod alphaW-val ((m <Serpentine>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snake_test-msg:alphaW-val is deprecated.  Use snake_test-msg:alphaW instead.")
  (alphaW m))

(cl:ensure-generic-function 'gamma-val :lambda-list '(m))
(cl:defmethod gamma-val ((m <Serpentine>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader snake_test-msg:gamma-val is deprecated.  Use snake_test-msg:gamma instead.")
  (gamma m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Serpentine>) ostream)
  "Serializes a message object of type '<Serpentine>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'alphaH))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'alphaW))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'gamma))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Serpentine>) istream)
  "Deserializes a message object of type '<Serpentine>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'alphaH) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'alphaW) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'gamma) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Serpentine>)))
  "Returns string type for a message object of type '<Serpentine>"
  "snake_test/Serpentine")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Serpentine)))
  "Returns string type for a message object of type 'Serpentine"
  "snake_test/Serpentine")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Serpentine>)))
  "Returns md5sum for a message object of type '<Serpentine>"
  "02f2567fa94bc953e03c031ebb7a9a8e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Serpentine)))
  "Returns md5sum for a message object of type 'Serpentine"
  "02f2567fa94bc953e03c031ebb7a9a8e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Serpentine>)))
  "Returns full string definition for message of type '<Serpentine>"
  (cl:format cl:nil "float64 alphaH~%float64 alphaW~%float64 gamma ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Serpentine)))
  "Returns full string definition for message of type 'Serpentine"
  (cl:format cl:nil "float64 alphaH~%float64 alphaW~%float64 gamma ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Serpentine>))
  (cl:+ 0
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Serpentine>))
  "Converts a ROS message object to a list"
  (cl:list 'Serpentine
    (cl:cons ':alphaH (alphaH msg))
    (cl:cons ':alphaW (alphaW msg))
    (cl:cons ':gamma (gamma msg))
))
