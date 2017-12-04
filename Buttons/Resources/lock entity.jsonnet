function(params) {
  [if "id" in params then "id"]: params.id,
  components: {
    Activation: {},
    Collision: {},
    LockRendering: {},
    PowerOutput: {},
    Transform: {},
    PhysicsBody: {
      body: "sensor body.json",
      [if "pos" in params then "pos"]: params.pos
    },
    Lock: {
      [if "index" in params then "index"]: params.index
    }
  }
}
