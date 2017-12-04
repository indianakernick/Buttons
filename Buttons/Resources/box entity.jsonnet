{
  make(pos_)::
    self.makeSize(pos_, [1, 1]),

  makeSize(pos_, size_)::
    {
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
