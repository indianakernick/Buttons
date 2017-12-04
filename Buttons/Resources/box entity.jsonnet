{
  makePos(pos_)::
    self.makePosSize(pos_, [1, 1]),

  makePosSize(pos_, size_):: {
    components: {
      BoxRendering: {},
      Transform: {},
      PhysicsBody: {
        body: "box body.json",
        pos: pos_,
        scale: size_
      }
    }
  },
}
