function(params) {
  components: {
    Activation: {},
    Animation: {
      speed: 1.5
    },
    Collision: {},
    Exit: {},
    ExitRendering: {},
    Transform: {},
    PhysicsBody: {
      body: "sensor body.json",
      [if "pos" in params then "pos"]: params.pos
    }
  }
}
