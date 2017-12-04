function(params) {
  components: {
    Activation: {
      speed: 4
    },
    Door: {},
    DoorRendering: {},
    Transform: {},
    PhysicsBody: {
      body: "door body.json",
      [if "pos" in params then "pos"]: params.pos,
      [if "size" in params then "scale"]: params.size,
      [if "rotation" in params then "rotation"]: params.rotation
    },
    PowerInput: {
      [if "in" in params then "in"]: params["in"],
      [if "operator" in params then "operator"]: params.operator
    }
  }
}
