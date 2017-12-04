function(params) {
  components: {
    Activation: {
      active: true
    },
    Collision: {},
    KeyRendering: {},
    Transform: {},
    PhysicsBody: {
      body: "sensor body.json",
      [if "pos" in params then "pos"]: params.pos
    },
    Key: {
      [if "index" in params then "index"]: params.index
    }
  }
}
