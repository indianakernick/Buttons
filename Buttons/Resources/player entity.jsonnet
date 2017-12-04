{
  makePos(pos_):: {
    components: {
      Collision: {},
      PlayerInput: {},
      PlayerJump: {},
      PlayerKeys: {},
      PlayerRendering: {},
      Transform: {},
      PhysicsBody: {
        body: "player body.json",
        pos: pos_
      }
    }
  }
}
