local common = import "common.jsonnet";

function(params) {
  components: common.checkParams(params, ["font scale", "pos", "text"]) {
    TextRendering: {
      sprite: "char 0",
      size:
        if "font scale" in params then
          params["font scale"]
        else
          2
      ,
      depth: common.getDepth("text")
    },
    Transform: common.getPos(params),
    Text: common.stringToIndicies(params.text)
  }
}
