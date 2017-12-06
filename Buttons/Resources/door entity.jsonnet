local common = import "common.jsonnet";

function(params) {
  components: {
    Activation: {
      speed: 4
    },
    Door: {},
    DoorRendering: {},
    Transform: {},
    PhysicsBody: common.getOrientTransform(params) + {
      [if "size" in params then "scale"]: params.size,
      body: "door body.json"
    },
    PowerInput: common.getPowerInput(params)
  }
}
