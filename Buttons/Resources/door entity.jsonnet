local common = import "common.jsonnet";

function(params) {
  components: {
    Activation: common.getActive(params) + {
      speed: 4
    },
    Door: {},
    DoorRendering: {},
    Transform: {},
    PhysicsBody: common.getOrientTransform(params) + {
      scale: if "height" in params then
        [1, params.height]
      else
        [1, 1]
      ,
      body: "door body.json"
    },
    PowerInput: common.getPowerInput(params)
  }
}
