{
  make(id_, pos_):: {
    id: id_,
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
        pos: pos_
      }
    }
  }
}
