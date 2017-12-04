{
  makePosSizeRot(pos_, size_, rotation_):: {
    components: {
      Activation: {
        speed: 4
      },
      Door: {},
      DoorRendering: {},
      Transform: {},
      PhysicsBody: {
        body: "door body.json",
        pos: pos_,
        scale: size_,
        rotation: rotation_
      }
    }
  },
  
  makeInPosSizeRot(in_, pos_, size_, rotation_)::
    self.makePosSizeRot(pos_, size_, rotation_) + {
      components: super.components + {
        PowerInput: {
          "in": in_
        }
      }
    },
  
  makeInPosSize(in_, pos_, size_):: self.makeInPosSizeRot(in_, pos_, size_, 0)
}
