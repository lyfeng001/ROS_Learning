// Auto-generated. Do not edit!

// (in-package snake_test.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Serpentine {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.alphaH = null;
      this.alphaW = null;
      this.gamma = null;
    }
    else {
      if (initObj.hasOwnProperty('alphaH')) {
        this.alphaH = initObj.alphaH
      }
      else {
        this.alphaH = 0.0;
      }
      if (initObj.hasOwnProperty('alphaW')) {
        this.alphaW = initObj.alphaW
      }
      else {
        this.alphaW = 0.0;
      }
      if (initObj.hasOwnProperty('gamma')) {
        this.gamma = initObj.gamma
      }
      else {
        this.gamma = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Serpentine
    // Serialize message field [alphaH]
    bufferOffset = _serializer.float64(obj.alphaH, buffer, bufferOffset);
    // Serialize message field [alphaW]
    bufferOffset = _serializer.float64(obj.alphaW, buffer, bufferOffset);
    // Serialize message field [gamma]
    bufferOffset = _serializer.float64(obj.gamma, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Serpentine
    let len;
    let data = new Serpentine(null);
    // Deserialize message field [alphaH]
    data.alphaH = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [alphaW]
    data.alphaW = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [gamma]
    data.gamma = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'snake_test/Serpentine';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '02f2567fa94bc953e03c031ebb7a9a8e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 alphaH
    float64 alphaW
    float64 gamma 
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Serpentine(null);
    if (msg.alphaH !== undefined) {
      resolved.alphaH = msg.alphaH;
    }
    else {
      resolved.alphaH = 0.0
    }

    if (msg.alphaW !== undefined) {
      resolved.alphaW = msg.alphaW;
    }
    else {
      resolved.alphaW = 0.0
    }

    if (msg.gamma !== undefined) {
      resolved.gamma = msg.gamma;
    }
    else {
      resolved.gamma = 0.0
    }

    return resolved;
    }
};

module.exports = Serpentine;
