function(params) {
  components: {
    Activation: {
      speed: 0.5
    },
    ShadowRendering: {},
    Transform: {
      [if "pos" in params then "pos"]: params.pos,
      [if "size" in params then "scale"]: params.size
    }
  }
}
