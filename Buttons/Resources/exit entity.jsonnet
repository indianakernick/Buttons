{
  makePos(pos_):: {
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
        pos: pos_
      }
    }
  }
}
