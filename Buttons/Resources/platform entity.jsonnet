{
  makePosSize(pos_, size_):: {
    components: {
      PlatformRendering: {},
      Transform: {},
      PhysicsBody: {
        body: "platform body.json",
        pos: pos_,
        scale: size_
      }
    }
  },
  
  makePos(pos_)::
    self.makePosSize(pos_, [1, 1])
}
