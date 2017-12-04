{
  makeIdEmitterPosRot(id_, emitter_, pos_, rot_):: {
    id: id_,
    components: {
      Activation: {},
      LaserDetectorRendering: {},
      PowerOutput: {},
      Transform: {
        pos: pos_,
        rotation: rot_
      },
      LaserDetector: {
        emitter: emitter_
      }
    }
  }
}
