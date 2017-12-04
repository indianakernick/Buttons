{
  makeIdStartEndRot(id_, start_, end_, rot_):: {
    id: id_,
    components: {
      Activation: {},
      LaserEmitterRendering: {},
      PowerInput: {
        on: true
      },
      PhysicsRayCast: {
        start: start_,
        end: end_
      },
      Transform: {
        pos: start_,
        rotation: rot_
      }
    }
  }
}
