
(cl:in-package :asdf)

(defsystem "snake_test-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Serpentine" :depends-on ("_package_Serpentine"))
    (:file "_package_Serpentine" :depends-on ("_package"))
  ))