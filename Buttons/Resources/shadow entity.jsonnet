{
  makePosSize(pos_, size_):: {
    components: {
      Activation: {
        speed: 0.5
      },
      ShadowRendering: {},
      Transform: {
        pos: pos_,
        scale: size_
      }
    }
  }
}
