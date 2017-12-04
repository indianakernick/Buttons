function(params) {
  [if "id" in params then "id"]: params.id,
  components: {
    Activation: {},
    LaserDetectorRendering: {},
    PowerOutput: {},
    Transform: {
      [if "pos" in params then "pos"]: params.pos,
      [if "rotation" in params then "rotation"]: params.rotation
    },
    LaserDetector: {
      emitter: params.emitter
    }
  }
}
