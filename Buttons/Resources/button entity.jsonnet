function(params) {
  // The id parameter is not optional
  id: params.id,
  components: {
    Activation: {
      speed: 8
    },
    Button: {},
    ButtonRendering: {},
    Collision: {},
    PowerOutput: {},
    Transform: {},
    PhysicsBody: {
      body: "button body.json",
      [if "pos" in params then "pos"]: params.pos
    }
  }
}
