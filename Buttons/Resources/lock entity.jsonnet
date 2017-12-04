{
  makeIdIndexPos(id_, index_, pos_):: {
    id: id_,
    components: {
      Activation: {},
      Collision: {},
      LockRendering: {},
      PowerOutput: {},
      Transform: {},
      PhysicsBody: {
        body: "sensor body.json",
        pos: pos_
      },
      Lock: {
        index: index_
      }
    }
  }
}
