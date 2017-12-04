{
  makeIndexPos(index_, pos_):: {
    components: {
      Activation: {},
      Collision: {},
      KeyRendering: {},
      Transform: {},
      PhysicsBody: {
        body: "sensor body.json",
        pos: pos_
      },
      Key: {
        index: index_
      }
    }
  }
}
