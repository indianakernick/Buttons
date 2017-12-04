function(params) {
  components: {
    Collision: {},
    PlayerInput: {},
    PlayerJump: {},
    PlayerKeys: {},
    PlayerRendering: {},
    Transform: {},
    PhysicsBody: {
      body: "player body.json",
      [if "pos" in params then "pos"]: params.pos
    }
  }
}
