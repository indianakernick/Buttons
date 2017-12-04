function(params) {
  id: params.id,
  components: {
    Activation: {},
    LaserEmitterRendering: {},
    PowerInput: {
      [if "in" in params then "in"]: params["in"],
      [if "operator" in params then "operator"]: params.operator,
      [if "on" in params then "on"]: params.on
    },
    PhysicsRayCast: {
      start: params.start,
      end: params.end
    },
    Transform: {
      pos: params.start,
      [if "rotation" in params then "rotation"]: params.rotation
    }
  }
}
