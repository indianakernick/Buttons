{
  makeIdPos(id_, pos_):: {
    id: id_,
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
        pos: pos_
      }
    }
  }
}
