local common = import "common.jsonnet";

function(params) {
  components: {
    TextRendering: {
      font: "Arial.ttf",
      size:
        if "size" in params then
          params.size
        else
          32
      ,
      "hori align": "center",
      "vert align": "middle"
    },
    Transform: common.getPos(params),
    Text:
      if "text" in params then
        params.text
      else
        ""
  }
}
