function(params) {
  [if "id" in params then "id"]: params.id,
  components: {
    Activation: {
      speed: 4
    },
    Collision: {},
    PowerOutput: {},
    Switch: {},
    SwitchRendering: {},
    Transform: {},
    PhysicsBody: {
      body: "sensor body.json",
      [if "pos" in params then "pos"]: params.pos
    }
  }
}
